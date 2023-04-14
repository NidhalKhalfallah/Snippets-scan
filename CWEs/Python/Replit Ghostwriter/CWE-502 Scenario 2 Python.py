import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request
  with open("data.yaml", "r") as f:
    data = yaml.load(f)
    return data