#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template, send_file

app = Flask(__name__)

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
    # todo obsluga bledow
    # if not request.json:
    #    abort(400)
    json_dict = request.form.to_dict()
    source = json_dict.get("source")
    target = json_dict.get("target")
    app.logger.info("Getting message from + %s + to + %s", source, target)

    # Cpp function here as return if move valid or not

    return jsonify({'legalMove': False}), 201

'''
@app.route('/todo/api/v1.0/tasks/<int:task_id>', methods=['PUT'])
def update_task(task_id):
    task = [task for task in tasks if task['id'] == task_id]
    if len(task) == 0:
        abort(404)
    if not request.json:
        abort(400)
    if 'title' in request.json and type(request.json['title']) != unicode:
        abort(400)
    if 'description' in request.json and type(request.json['description']) is not unicode:
        abort(400)
    if 'done' in request.json and type(request.json['done']) is not bool:
        abort(400)
    task[0]['title'] = request.json.get('title', task[0]['title'])
    task[0]['description'] = request.json.get('description', task[0]['description'])
    task[0]['done'] = request.json.get('done', task[0]['done'])
    return jsonify({'task': task[0]})
'''


if __name__ == '__main__':
    app.run(debug=True)