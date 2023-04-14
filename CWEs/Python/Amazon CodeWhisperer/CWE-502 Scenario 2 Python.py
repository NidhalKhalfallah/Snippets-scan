import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request
    data = await request.json()
    #Load the YAML file
    with open("data.yaml", "r") as f:
        yaml_data = yaml.load(f, Loader=yaml.FullLoader)
    #Return the data
    return yaml_data