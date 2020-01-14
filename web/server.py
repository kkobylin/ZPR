#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template, send_file
import sys
sys.path.append('../chess_engine')
import libchesslib
app = Flask(__name__)

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
    app.logger.info("Getting message from + %s + to + %s", source, target)

    end_of_game = 'none'
    opponent_move = 'none'
    legal_move = libchesslib.ifMovePossible(target, source)
    if(legal_move):
        end_of_game = libchesslib.checkForWin()

    if(legal_move and end_of_game == 'none'):
        opponent_move = libchesslib.opponentMove()

    if end_of_game != 'none':
        app.logger.info("End of the game")

    return jsonify({'legalMove': legal_move, 'endOfGame':end_of_game, 'opponentMove':opponent_move}), 201


if __name__ == '__main__':
    app.run(debug=True)