from PIL import Image
import matplotlib.pyplot as plt

# XPMファイルを開く
image = Image.open('./kishi.xpm')

# 画像を表示する
plt.imshow(image)
plt.axis('off')
plt.show()
