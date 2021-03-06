'''
/**
 * @file server.py
 * @author Krzysztof Kobyliński (k.kobylinski98@gmail.com)
 * @brief Server of the application
 * Communicate frontend with chess logic 
 * @version 1.0
 * @date 2020-01-15
 */
'''
#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template, send_file
import sys
sys.path.append('../chess_engine')
import libchesslib
app = Flask(__name__)


@app.route('/')
def index():
    return render_template('index.html')


# Uri from chessboard_js library
@app.route('/img/chesspieces/wikipedia/<piece>.png', methods=['GET'])
def get_image(piece):
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

    if(legal_move ):
        opponent_move = libchesslib.opponentMove()
    
    if(legal_move):
        end_of_game = libchesslib.checkForWin()

    if end_of_game != 'none':
        app.logger.info("End of the game")

    return jsonify({'legalMove': legal_move, 'endOfGame':end_of_game, 'opponentMove':opponent_move}), 201


@app.after_request
def add_headers(response):
    response.headers.add('Access-Control-Allow-Origin', '*')
    response.headers.add('Access-Control-Allow-Headers', 'Content-Type,Authorization')
    return response


if __name__ == '__main__':
    app.run(debug=True)