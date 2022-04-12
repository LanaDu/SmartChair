import pandas as pd
import matlab.engine
import mat73
import scipy.io as sio
import predictFamBT

# dummy data
dummy_path = r"C:\Users\conni\OneDrive\Documents\connie\Smart Chair\DummyData.xlsx"
dummydata = pd.read_excel(dummy_path)
# test file to export dummy data
dummy_out = r"C:\Users\conni\OneDrive\Documents\connie\Smart Chair\DummyOutput"

# create empty xl file
writer = pd.ExcelWriter(f'{dummy_out}.xlsx', engine='openpyxl')

all_sensors = pd.DataFrame(columns = ['Sensor', 'Value'])
i = 0
while i != len(dummydata):
    # read 13 sensor values from dummydata
    dummydata_sp = dummydata.iloc[i:i + 13]
    sensors = list(dummydata_sp['Sensor'])
    vals = list(dummydata_sp['Value'])
    sensors13 = pd.DataFrame(list(zip(sensors, vals)), columns=['Sensor', 'Value'])
    all_sensors = all_sensors.append(sensors13)
    # export to excel
    i += 13

    # eng = matlab.engine.start_matlab(background = True)
    # labels = eng.example(sensors)
    # eng.quit()
    # print(svmpy)

# all_sensors.to_excel(writer, index = False)
# writer.save()


