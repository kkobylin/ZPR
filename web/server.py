#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template, send_file
import sys
sys.path.append('../chess_engine')
import libchesslib
app = Flask(__name__)

temp = True

# todo change path to index.html
@app.route('/')
def index():
    return render_template('index.html')


# Uri from chessboard_js library
# todo change url for Windows also
@app.route('/img/chesspieces/wikipedia/<piece>.png', methods=['GET'])
def get_image(piece):
    # filename = 'templates\\img\\chesspieces\\wikipedia\\' + piece + '.png'
    filename = 'templates/img/chesspieces/wikipedia/' + piece + '.png'
    return send_file(filename, mimetype='image/png')


@app.route('/api/post', methods=['POST'])
def receive_msg():

    json_dict = request.form.to_dict()
    source = json_dict.get("source")
    target = json_dict.get("target")
    piece = json_dict.get("piece")
    app.logger.info("Getting message from + %s + to + %s", source, target)

    legal_move = libchesslib.ifMovePossible(target, source)
    app.logger.info("legal move - %s", legal_move)
    end_of_game = libchesslib.checkForWin()
    app.logger.info("end of game - %s", end_of_game)
    opponent_move = libchesslib.opponentMove()
    app.logger.info("opponent_move - %s", opponent_move)

    if end_of_game != 'none':
        app.logger.info("End of the game")

    return jsonify({'legalMove': legal_move, 'endOfGame':end_of_game, 'opponentMove':opponent_move}), 201


if __name__ == '__main__':
    app.run(debug=True)
