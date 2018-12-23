import cv2
import numpy as np
import time

upper_body_cascade = cv2.CascadeClassifier('haarcascade_upperbody.xml')

body_cascade = cv2.CascadeClassifier('haarcascade_fullbody.xml')

lower_body_cascade = cv2.CascadeClassifier('haarcascade_lowerbody.xml')

profil_face_cascade = cv2.CascadeClassifier('haarcascade_profileface.xml')

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

eye_cascade = cv2.CascadeClassifier('haarcascade_eye.xml')

smile_cascade = cv2.CascadeClassifier('haarcascade_smile.xml')

img = cv2.imread('Test6m.jpg') 

start = time.time()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

upper_body = upper_body_cascade.detectMultiScale(gray, 1.3, 5)
for (ux, uy, uw, uh) in upper_body:
    cv2.rectangle(img, (ux, uy), (ux+uw, uy+uh), (255, 255, 0), 2)

body = body_cascade.detectMultiScale(gray, 1.3, 5)
for (bx, by, bw, bh) in body:
    cv2.rectangle(img, (bx, by), (bx+bw, by+bh), (0, 0, 255), 2)

lower_body = lower_body_cascade.detectMultiScale(gray, 1.3, 5)
for (lx, ly, lw, lh) in lower_body:
    cv2.rectangle(img, (lx, ly), (lx+lw, ly+lh), (0, 255, 255), 2)

profil_face = profil_face_cascade.detectMultiScale(gray, 1.3, 5)
for (px, py, pw, ph) in profil_face:
    cv2.rectangle(img, (px, py), (px+pw, py+ph), (255, 255, 255), 2)

faces = face_cascade.detectMultiScale(gray, 1.3, 5)
for (x, y, w, h) in faces:
    cv2.rectangle(img, (x, y), (x + w, y + h), (255, 0, 0), 2)
    roi_gray = gray[y:y + h, x:x+ w]
    roi_color = img[y:y + h, x:x+ w]

    eyes = eye_cascade.detectMultiScale(roi_gray)
    for (ex, ey, ew, eh) in eyes:
        cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh), (0,255,0), 1)

    smile = smile_cascade.detectMultiScale(roi_gray)
    for (sx, sy, sw, sh) in smile:
        cv2.rectangle(roi_color, (sx, sy), (sx+sw, sy+sh), (255,0,255), 2)

end = time.time()
print(end-start, '- время работы')

fw = 900
rr = float(fw) / img.shape[1]
dim = (fw, int(img.shape[0]*rr))
resized = cv2.resize(img, dim, interpolation = cv2.INTER_AREA)

cv2.imshow('img', resized)
cv2.waitKey(0)
cv2.destroyAllWindows()
