import QtQuick 2.0
import QtQuick 2.2

Canvas {
    width:1000;
    height:800;
    id:root;
    Image{
        id:poster;
        source:"start1.jpg";
        visible:false;
        onStatusChanged: {
            if(status == Image.Ready)
            {
                root.requestPaint();
            }
        }
    }

    onPaint: {
        var ctx = getContext("2d");
        ctx.drawImage(poster,0,0);
    }

}
