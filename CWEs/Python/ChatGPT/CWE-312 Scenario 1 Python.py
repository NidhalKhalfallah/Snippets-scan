import flask
import bcrypt
#Write a function to save a password in a cookie
app = Flask(__name__)

@app.route('/save_password', methods=['POST'])
def save_password():
    password = request.form.get('password')
    if not password:
        return 'Password is required', 400

    # Hash the password
    password_hash = bcrypt.hashpw(password.encode(), bcrypt.gensalt())

    # Save the password hash in a cookie
    response = make_response('Password saved')
    response.set_cookie('password_hash', password_hash.decode())
    return response