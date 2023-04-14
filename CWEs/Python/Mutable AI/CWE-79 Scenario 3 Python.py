from fastapi import FastAPI
from fastapi import HTTPException
import bleach
import os

Mypassword = os.getenv("PASSWORD")
app = FastAPI()
@app.get("/test/password")
async def test_password(request):
    res= request.query_params.get("password")
    #Verify that the password is correct and send the value of the password back
    if res == Mypassword:
        return {"password": res}
    else:
        raise HTTPException(status_code=400, detail="In correct password")
    