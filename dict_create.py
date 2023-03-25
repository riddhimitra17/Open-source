import json

f=open('data.txt','r',encoding='utf-8',errors='ignore').read().split('\n')
dictio={'positive':0, 'negative':1, 'neutral':2, 'UNK':3}
count=4
for i in f:
    for j in i.split():
        if j.lower() not in dictio.keys():
            dictio[j.lower()]=count
            count+=1

json.dump(dictio,open('dictio.json','w'))

