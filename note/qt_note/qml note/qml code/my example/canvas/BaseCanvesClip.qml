import QtQuick 2.2
Rectangle{
    anchors.fill: parent.fill;
    anchors.left: parent.left;
    anchors.top: parent.top;
    id:rec1;

Canvas {
    width: 800;
    height: 800;
    contextType: "2d";
    property string comicRole: "qin1.jpg";
    id:can1;
    anchors.left: rec1.left;
    anchors.top: rec1.top;
    anchors.topMargin: 20;
    onPaint:{
        context.lineWidth = 2;
        context.strokeStyle = "blue";
        //context.fillStyle = "#eeeeee";//Qt.rgba(0.3, 0.5, 0,7, 0.3);
        //context.fillStyle = Qt.rgba(0.3, 0.5, 0,7, 0.3);

        context.save();

        context.beginPath();
        context.arc(180, 150, 20,0,Math.PI *2);
//        context.restore();

//        context.save();
        context.moveTo(180, 230);
        context.lineTo(420, 280);
        context.lineTo(160, 320);

        context.closePath();
        context.clip();
        context.drawImage(comicRole,50 ,50, 400, 400);
        context.stroke();
        context.fill();

//        context.restore();


//        context.save();
//        context.drawImage(comicRole,100 ,100, 400, 400, 0, 0, 600, 600);


        context.restore();
//        context.clip();

//        context.save();
//        context.rotate(Math.PI /5);
//        context.font = "italic bold 32px serif";
//        context.fillStyle = "red";
//        context.restore();
    }

    Component.onCompleted: loadImage(comicRole);
    onImageLoaded: requestPaint();
}
}
