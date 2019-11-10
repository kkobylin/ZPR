#!flask/bin/python
from flask import Flask, jsonify, request, make_response, abort, render_template

app = Flask(__name__)

msgs_from_cpp = [
    {
        'valid': False,
        'message': "Forbidden move"
    },
    {
        'valid': True,
        'message': "F3"
    }
]

msgs_from_js = []


@app.route('/')
def index():
    return render_template('/client/index.html')


@app.route('/api/test', methods=['GET'])
def send_msgs():
    return jsonify({'messages' : msgs_from_js})


@app.route('/api/post', methods=['POST'])
def receive_msg():
    # todo obsluga bledow
    # if not request.json:
    #    abort(400)
    msg = request.get_json()

    msgs_from_js.append(msg)
    return jsonify({'valid': True}), 201


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