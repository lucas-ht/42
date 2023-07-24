from flask import Flask, render_template
app = Flask(__name__)

import logging
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

@app.route('/')
def _():
    return render_template('index.html')

if __name__ == '__main__':
    app.run()