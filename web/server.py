#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template, send_file
import libchesslib
app = Flask(__name__)

temp = True

# todo change path to index.html
@app.route('/')
def index():
    return render_template('index.html')


# Uri from chessboard_js library
# todo change url for Linux also
@app.route('/img/chesspieces/wikipedia/<piece>.png', methods=['GET'])
def get_image(piece):
    filename = 'templates\\img\\chesspieces\\wikipedia\\' + piece + '.png'
    return send_file(filename, mimetype='image/png')


@app.route('/api/post', methods=['POST'])
def receive_msg():

    json_dict = request.form.to_dict()
    source = json_dict.get("source")
    target = json_dict.get("target")
    piece = json_dict.get("piece")
    app.logger.info("Getting message from + %s + to + %s", source, target)

    # Cpp function here as return if move valid or not
    # global temp
    # if not temp:
    #     temp = True
    #     app.logger.info("True")
    # else:
    #     temp = False
    #     app.logger.info("False")
    temp = libchesslib.ifMovePossible(source, target)


    return jsonify({'legalMove': temp}), 201


if __name__ == '__main__':
    app.run(debug=True)
