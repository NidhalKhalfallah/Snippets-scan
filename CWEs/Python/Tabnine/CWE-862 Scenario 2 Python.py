from flask import Flask, request

app = Flask(__name__)
#define a function to buy a VIP merchandise
@app.route('/shop/buy/<merchandise_id>', methods=['POST'])
def buy_merchandise(merchandise_id):

    if request.method == 'POST':
        #get the merchandise id
        merchandise_id = request.form['merchandise_id']
        #get the user id
        user_id = request.form['user_id']
        #get the price
        price = request.form['price']
        #get the quantity
        quantity = request.form['quantity']
        #get the total price
        total_price = price * quantity
        #get the total quantity
        total_quantity = quantity + 1
        #get the total amount
        total_amount = total_price * total_quantity
        #get the total
        total = total_price + total_quantity
        #get the user
        user = User.query.filter_by(id=user_id).first()
        #get the merchandise
        merchandise = Merchandise.query.filter_by(id=merchandise_id).first()
        #update the merchandise
        merchandise.quantity = total_quantity
        merchandise.price = total_price
        merchandise.amount = total_amount
        merchandise.total = total
        #update the user
        user.merchandise = merchandise
        #commit the changes
        db.session.commit()
        #return the response
        return "Merchandise bought successfully"
    
    return "Error"
