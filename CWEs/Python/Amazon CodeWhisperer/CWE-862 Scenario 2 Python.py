from flask import Flask, request

app = Flask(__name__)
#define a function to buy a VIP merchandise
@app.route('/shop/buy/<merchandise_id>', methods=['POST'])
def buy_merchandise(merchandise_id):
    #do something to buy the merchandise
    return 'You bought a VIP merchandise: ' + merchandise_id