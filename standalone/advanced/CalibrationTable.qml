// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.0

Rectangle
{
    id: main
    x: 0;
    y: 0;
    color:  Qt.rgba(50/255, 50/255, 50/255,1);
    width:  112;
    height: 112;
    border.width: 2;
    border.color: Qt.rgba(0/255, 174/255, 239/255,1);

    //Draw and position blocks
    function drawBlock(x,y,size)
    {
        //console.log("drawBlock called............");
        console.log(x);
        console.log(y);
        console.log(size);

        var newObject = Qt.createQmlObject('import QtQuick 1.0; Rectangle {color: Qt.rgba(230/255, 0/255, 134/255,1);}', main, "block");

        newObject.x = x;
        newObject.y = y;
        newObject.height = 2;
        newObject.width = size;

        console.log("drawBlock called............");
    }

        //Clears all blocks
        function clearBlocks()
        {
            console.log("clearBlock called............");

            var newObject = Qt.createQmlObject('import QtQuick 1.0; Rectangle {color: Qt.rgba(50/255, 50/255, 50/255,1); width: 112; height: 112;}', main, "clear");
        }
    }
