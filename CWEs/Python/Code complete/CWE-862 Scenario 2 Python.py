from flask import Flask, request

app = Flask(__name__)
#define a function to buy a VIP merchandise
@app.route('/shop/buy/<merchandise_id>', methods=['POST'])
def buy_merchandise(merchandise_id):
    print("buy merchandise %s" % merchandise_id)
    return "success"


@app.route('/shop/get/<merchandise_id>', methods=['GET'])
def get_merchandise(merchandise_id):
    print("get merchandise %s" % merchandise_id)
    return "success"


if __name__ == '__main__':
    app.run()
