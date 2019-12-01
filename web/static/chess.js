postURI = 'http://localhost:5000/api/post';

/* Global variable to define whether move or not */
var snapBack;

var chessConfig = {
    draggable: true,
    position: 'start',
    onDrop: onDrop,
    /* Prevent from moving black pieces */
    onDragStart: onDragStart
};

var board = Chessboard("myBoard", chessConfig);
//$(window).resize(board.resize);
$('#showPositionBtn').on('click', clickShowPositionBtn);

function clickShowPositionBtn () {
    console.log('Current position as an Object:');
    console.log(board.position());

    console.log('Current position as a FEN string:');
    console.log(board.fen());
}

function onDragStart (source, piece, position, orientation) {
    if ((orientation === 'white' && piece.search(/^w/) === -1) ||
        (orientation === 'black' && piece.search(/^b/) === -1)) {
        return false;
    }
}

function onDrop (source, target, piece, newPos, oldPos, orientation) {
    var jsonToSend = {
        "source": source,
        "target": target
    };

    $.ajax({
        type: "POST",
        url: postURI,
        data: jsonToSend,
        success: function (result) {
            snapBack = (result.legalMove === false);
        },
        error: function (result) {
            alert("error:" + result);
        }
    });
    if (snapBack) return 'snapback';
}