# �����Ҫ�Ŀ�
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
from matplotlib.patches import Circle

# ���������Ļ������������
r1 = 4  # ����İ뾶
r2 = 2  # ������ı߳�
h1 = 10  # Բ����ĸ߶�
h2 = 6  # Բ׶��ĸ߶�

# ����Բ����ĵײ�Բ��
circle1 = Circle((0, 0), r1, color='gray', alpha=0.5)

# ��������������ĵײ���
rect1 = [(0, -r1), (0, -r1-h2), (-r2, -r1-h2), (-r2, -r1)]
rect2 = [(0, -r1), (0, -r1-h2), (r2, -r1-h2), (r2, -r1)]
rect1_face = Poly3DCollection([rect1], alpha=0.5, facecolor='gray')
rect2_face = Poly3DCollection([rect2], alpha=0.5, facecolor='gray')

# ��������ͼ�ķ�Χ������������
plt.xlim(-r1-r2, r1)
plt.ylim(-r1-h2, h1)
plt.xlabel('X')
plt.ylabel('Z')

# ��ӵײ�Բ�κ͵ײ��浽ͼ��
plt.gca().add_patch(circle1)
plt.gca().add_collection(rect1_face)
plt.gca().add_collection(rect2_face)

# ��ʾͼ��
plt.show()
