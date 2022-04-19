from __future__ import print_function
import pandas as pd
import predictFamBT
import matlab
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sb
from matplotlib.colors import ListedColormap
import TkGui
import openpyxl


def create_HM(dataBot, dataTop):
    # fig size is (rows, columns)
    f, ax = plt.subplots(2, 1, figsize=(6, 6))
    hmTop = sb.heatmap(dataTop, cmap=ListedColormap(['green', 'orange', 'red']), ax=ax[0])
    hmTop.set_xlabel('X-Axis', fontsize=10)
    hmTop.set_ylabel('Y-Axis', fontsize=10)

    hmBot = sb.heatmap(dataBot, cmap=ListedColormap(['green', 'orange', 'red']), ax=ax[1])
    hmBot.set_xlabel('X-Axis', fontsize=10)
    hmBot.set_ylabel('Y-Axis', fontsize=10)
    plt.show()
    return f


def data_hm(inputs):
    #inputs = [0.62, 0.34, 3.63, 0.47, 1.73, 1.43, 1.66, 1.89, 1.6, 1.93, 1.16, 0.85, 1.08]
    dataBot = np.array(
        [inputs[4], inputs[5], inputs[6], inputs[7], inputs[8], inputs[9], inputs[10], inputs[11], inputs[12]]).reshape(
        3, 3)
    dataTop = np.array([inputs[0], inputs[1], inputs[2], inputs[3]]).reshape(2, 2)
    return dataBot, dataTop
# dummy data

dummy_path = r"C:\Users\conni\OneDrive\Documents\connie\Smart Chair\DummyData.xlsx"
dummydata = pd.read_excel(dummy_path)
# test file to export dummy data
#dummy_out = r"C:\Users\conni\OneDrive\Documents\connie\Smart Chair\DummyOutput"

# create empty xl file
#writer = pd.ExcelWriter(f'{dummy_out}.xlsx', engine='openpyxl')

#all_sensors = pd.DataFrame(columns = ['Sensor', 'Value'])


i = 0
while i != len(dummydata):
    # read 13 sensor values from dummydata
    dummydata_sp = dummydata.iloc[i:i + 13]
    sensors = list(dummydata_sp['Sensor'])
    vals = list(dummydata_sp['Value'])
    #sensors13 = pd.DataFrame(list(zip(sensors, vals)), columns=['Sensor', 'Value'])
    #all_sensors = all_sensors.append(sensors13)

    # TkGui.main1(vals)
    # export to excel

    my_predictFamBT = predictFamBT.initialize()

    sensorDataIn = matlab.double(vals, size=(1, 13))
    labelOut = my_predictFamBT.predictFamBT(sensorDataIn)
    print(labelOut, sep='\n')

    my_predictFamBT.terminate()

    i += 13


    #
    # data = data_hm(vals)
    # # heat map
    # dataBot = data[0]
    # dataTop = data[1]
    # fig_HM = create_HM(dataBot, dataTop)



# all_sensors.to_excel(writer, index = False)
# writer.save()


