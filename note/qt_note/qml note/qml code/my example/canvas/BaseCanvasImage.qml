import QtQuick 2.0
import QtQuick 2.2

Canvas{
    anchors.fill: parent.fill;
    width:1200;
    height:1000;
    id: root;

    property var start:"start.jpg";
    property var imageUrl: "start1.jpg"

    onPaint:{
        var ctx = getContext("2d");
        ctx.drawImage(imageUrl,200,0);
        ctx.drawImage(start,0,0);
    }

    Component.onCompleted: {
        loadImage(start);
        loadImage(imageUrl);
    }
    onImageLoaded: requestPaint();
}
