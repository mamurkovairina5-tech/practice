import cv2
import numpy as np

image = cv2.imread("test_2.jpg")
cv2.imshow("Original", image)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

lower_bound = np.array([0, 20, 20], np.uint8)
upper_bound = np.array([180, 255, 255], np.uint8)

mask = cv2.inRange(hsv_image, lower_bound, upper_bound)
cv2.imshow("Mask", mask)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)

if len(sorted_contours) > 0:
    largest_contour = sorted_contours[0]
    x, y, w, h = cv2.boundingRect(largest_contour)
    cv2.rectangle(image, (x, y), (int(x + w), int(y + h)), (0, 0, 255), 3)

    center_x = int(x + w / 2)
    center_y = int(y + h / 2)

    cv2.circle(image, (center_x, center_y), 7, (255, 0, 100), -1) 
    print(f"Центр самого большого объекта: X={center_x}, Y={center_y}")

cv2.imshow("Result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()