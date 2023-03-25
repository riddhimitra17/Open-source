import numpy as np
import tensorflow
from tensorflow.keras.models import Model, load_model
from tensorflow.keras.layers import Input, Embedding, LSTM, Dense

text=np.load('text.npy')
labels=np.load('labels.npy')

train_x=text[:230000]
train_y=labels[:230000]
test_x=text[230000:]
test_y=labels[230000:]

inp=Input(shape=(56,))
emb=Embedding(input_dim=19805, output_dim=100, mask_zero=True)(inp)
lstm=LSTM(64)(emb)
out=Dense(np.amax(test_y)+1, activation='softmax')(lstm)
model=Model(inp,out)
model.compile(optimizer="rmsprop", loss="sparse_categorical_crossentropy", metrics=["acc"])
model.fit(train_x,train_y, batch_size=128,epochs=30, verbose=1, validation_split=0.1)
model.save('model.h5')

# for testing, disable the moidel.fit code
model=load_model('/content/drive/MyDrive/sentiment/model.h5')
prediction=model.predict(test_x)
for i in prediction:
  if np.argmax(i)==0:
    print ('positive')
  elif np.argmax(i)==1:
    print ('negative')
  elif np.argmax(i)==2:
    print ('neutral')