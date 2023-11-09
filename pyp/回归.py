# 回归问题图例
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
%matplotlib inline
font = FontProperties(fname='/Library/Fonts/Heiti.ttc')

x = np.linspace(0, 200, 10)
y = 10*x

plt.plot(x, y)
plt.xlabel('房子面积', fontproperties=font, fontsize=15)
plt.ylabel('房价', fontproperties=font, fontsize=15)
plt.title('回归问题图例', fontproperties=font, fontsize=20)
plt.show()