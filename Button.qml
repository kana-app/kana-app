import QtQuick 2.0


Rectangle {
    id: container
    // The caption property is an alias to the text of the Text element, so Button users can set the text
    property alias caption: txt.text
    // The clicked signal is emitted whenever the button is clicked, so Button users can respond
    signal clicked

    // The button is set to have rounded corners and a thin black border
    radius: 4
    border.width: 1
    // This button has a fixed size, but it could resize based on the text
    width: 160
    height: 40

    // A SystemPalette is used to get colors from the system settings for the background
    SystemPalette { id: sysPalette }

    gradient: Gradient {

        // The top gradient is darker when 'pressed', all colors come from the system palette
        GradientStop { position: 0.0; color: ma.pressed ? sysPalette.dark : sysPalette.light }

        GradientStop { position: 1.0; color: sysPalette.button }
    }

    Text {
        id: txt
        // This is the default value of the text, but most Button users will set their own with the caption property
        text: "Button"
        font.bold: true
        font.pixelSize: 16
        anchors.centerIn: parent
    }

    MouseArea {
        id: ma
        anchors.fill: parent
        // This re-emits the clicked signal on the root item, so that Button users can respond to it
        onClicked: container.clicked()
    }
}
