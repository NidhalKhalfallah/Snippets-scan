import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request
    data = await request.json()
    #Load the YAML file
    with open("config.yaml", 'r') as stream:
        try:
            #Load the YAML file
            config = yaml.safe_load(stream)
            #Return the YAML file
            return config
        except yaml.YAMLError as exc:
            print(exc)
            