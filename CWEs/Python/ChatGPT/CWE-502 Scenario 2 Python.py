import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request: Request):
    #Load and parse the data from the HTTP request
    data = await request.json()
    # Process the data as needed
    return {"status": "success"}