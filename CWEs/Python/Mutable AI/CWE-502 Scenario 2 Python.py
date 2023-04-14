import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request
    data = await request.body()
    data = yaml.load(data)
    #Do something with the data
    return data