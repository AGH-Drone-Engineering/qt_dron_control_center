import QtQuick 2.15
import QtLocation 6.6
import QtPositioning 6.6
import QtQuick.Controls 2.15

Rectangle {
    Plugin {
        id: mapPlugin
        name: "osm"
        PluginParameter { name: "osm.useragent"; value: "My great Qt OSM application" }
    }

    ListModel {
        id: markerModel
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(50.2709, 18.6722)
        zoomLevel: 14

        MapItemView {
            model: markerModel


            delegate: MapQuickItem {
                property int index: index
                property real selectedLat: latitude
                property real selectedLon: longitude
                property int selectedIndex: index

                coordinate: QtPositioning.coordinate(latitude, longitude)
                anchorPoint: Qt.point(17, 36)

                sourceItem: Item {
                    width: 34
                    height: 40

                    Image {
                        id: pinImg
                        source: "qrc:/pin.png"
                        anchors.fill: parent
                    }

                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.LeftButton | Qt.RightButton
                        propagateComposedEvents: false
                        preventStealing: true

                        onClicked: function(mouse) {
                            if (mouse.button === Qt.LeftButton) {
                                popup.open()
                            } else if (mouse.button === Qt.RightButton) {
                                markerModel.remove(index)
                            }
                        }
                    }

                    Popup {
                        id: popup
                        width: 450
                        height: 150
                        modal: true
                        focus: true
                        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
                        x: selectedLat


                        y: (parent.height - height) / 2

                        Rectangle {
                            anchors.fill: parent
                            color: "#1e1e2f"
                            radius: 10
                            border.color: "#5e5e5e"
                            border.width: 1

                            Column {
                                spacing: 10
                                anchors.centerIn: parent

                                Text {
                                    text: "Wybierz drona do wysłania:"
                                    color: "#e0e0e0"
                                    font.bold: true
                                    font.pixelSize: 14
                                    horizontalAlignment: Text.AlignHCenter
                                    anchors.horizontalCenter: parent.horizontalCenter
                                }

                                Row {
                                    spacing: 12
                                    Repeater {
                                        model: ["DRONE1", "DRONE2", "DRONE3", "DRONE4"]
                                        delegate: Rectangle {
                                            width: 80
                                            height: 36
                                            radius: 6
                                            // color: Gradient {
                                            //     GradientStop { position: 0.0; color: "#00c6ff" }
                                            //     GradientStop { position: 1.0; color: "#0072ff" }
                                            // }

                                            Text {
                                                anchors.centerIn: parent
                                                text: modelData
                                                color: "#000000"
                                                font.bold: true
                                                font.pixelSize: 12
                                            }

                                            MouseArea {
                                                anchors.fill: parent
                                                onClicked: {
                                                    markerModel.setProperty(selectedIndex, "droneId", modelData)
                                                    coordReceiver.handleSelection(modelData, selectedLat, selectedLon)
                                                    popup.close()
                                                }
                                            }
                                        }
                                    }
                                }

                                Button {
                                    text: "Zamknij"
                                    anchors.horizontalCenter: parent.horizontalCenter
                                    background: Rectangle {
                                        color: "#004080"
                                        radius: 6
                                    }
                                    contentItem: Text {
                                        text: "Zamknij"
                                        color: "white"
                                        anchors.centerIn: parent
                                    }
                                    onClicked: popup.close()
                                }
                            }
                        }
                    }

                }
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            propagateComposedEvents: true
            preventStealing: false

            property var lastPos: null

            onPressed: {
                lastPos = Qt.point(mouse.x, mouse.y)
            }

            onPositionChanged: {
                if (lastPos) {
                    let dx = mouse.x - lastPos.x
                    let dy = mouse.y - lastPos.y
                    map.pan(-dx, -dy)
                    lastPos = Qt.point(mouse.x, mouse.y)
                }
            }

            onReleased: {
                lastPos = null
            }

            onDoubleClicked: {
                let coord = map.toCoordinate(Qt.point(mouse.x, mouse.y))
                markerModel.append({
                    latitude: coord.latitude,
                    longitude: coord.longitude,
                    droneId: "DRONE1"
                })
            }

            onWheel: {
                if (wheel.angleDelta.y > 0)
                    map.zoomLevel += 0.5
                else
                    map.zoomLevel -= 0.5
            }
        }
    }
}
