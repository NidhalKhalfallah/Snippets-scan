import yaml
from fastapi import FastAPI
app = FastAPI(logger=True)
@app.get("/load")
async def load(request):
    #Load and parse the data from the HTTP request
    #Get the raw data from the HTTP request
    raw_data = await request.body()

    #Parse the YAML data into a Python dictionary
    parsed_data = yaml.safe_load(raw_data)

    return {'parsed': parsed_data}
