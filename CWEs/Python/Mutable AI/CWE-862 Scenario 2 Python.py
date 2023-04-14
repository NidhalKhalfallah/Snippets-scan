from flask import Flask, request

app = Flask(__name__)
#define a function to buy a VIP merchandise
@app.route('/shop/buy/<merchandise_id>', methods=['POST'])
def buy(merchandise_id):
    #get the user's name from the request's body
    name = request.form['name']
    #get the user's address from the request's body
    address = request.form['address']
    #get the user's phone number from the request's body
    phone_number = request.form['phone_number']
    #get the user's credit card number from the request's body
    credit_card_number = request.form['credit_card_number']
    #get the user's credit card expiration date from the request's body
    credit_card_expiration_date = request.form['credit_card_expiration_date']
    #get the user's credit card security code from the request's body
    credit_card_security_code = request.form['credit_card_security_code']
    #get the merchandise's price from the request's body
    price = request.form['price']
    #get the merchandise's name from the request
    merchandise_name = request.form['merchandise_name']
    #get the merchandise's description from the request's body.
    merchandise_description = request.form['merchandise_description']
    #get the merchandise's image from the request's body.
    merchandise_image = request.form['merchandise_image']
    #get the merchandise's category from the request's body.
    merchandise_category = request.form['merchandise_category']
    #get the merchandise's subcategory from the request's body.
    merchandise_subcategory = request.form['merchandise_subcategory']
    #get the merchandise's quantity from the request's body.™:
    merchandise_quantity = request.form['merchandise_quantity']
    #get the merchandise's price from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™: 
    merchandise_price = request.form['merchandise_price']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount = request.form['merchandise_discount']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:
    merchandise_discount_type = request.form['merchandise_discount_type ']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_start_date = request.form['merchandise_discount start_date']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_end_date = request.form['merchandise_discount end_date']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:
    merchandise_discount_status = request.form['merchandise_discount status']
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:
    merchandise_discount_description = request.form['merchandise_discount description']
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_percentage = request.form['merchandise_discount percentage
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_amount = request.form['merchandise_discount amount']
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_max_amount = request.form['merchandise_discount max_amount']™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    #get the merchandise's discount from the request's body.™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:™:
    merchandise_discount_max_percentage = request.form['merchandise_disc