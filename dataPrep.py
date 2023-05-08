import pandas as pd

data = pd.read_csv("diagnosis.csv")

print(data)

print(data.iloc[:, 0])

firstCol = data.iloc[:, 0]
firstCol = firstCol.to_list()
for i in range(len(data.iloc[:, 0])):
    data.iloc[i, 0] = data.iloc[i, 0].replace(",", '.')
    data.iloc[i, 0] = float(data.iloc[i, 0])

    
    
max = 0
for i in range(len(data.iloc[:, 0])):
    if data.iloc[i, 0] > max:
        max = data.iloc[i, 0]
for i in range(len(data.iloc[:, 0])):
    data.iloc[i, 0]/=max
for j in range(len(data.iloc[0])):
    for i in range(len(data.iloc[:, j])):
        try:
            data.iloc[i, j] = data.iloc[i, j].replace("no", '0')
            data.iloc[i, j] = data.iloc[i, j].replace("yes", '1')
        except:
            print("probably a float or smth")
    

print(data.iloc[:, 0])

data.to_csv("preppedData.csv", index=False, header=False)




