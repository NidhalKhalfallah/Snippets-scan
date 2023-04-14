import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request

    with open('config.yaml', 'r') as stream:
        try:
            data = yaml.safe_load(stream)
        except yaml.YAMLError as exc:
            print(exc)
    return data