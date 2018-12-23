from __future__ import print_function

import numpy as np
import cv2
import time
from common import anorm2, draw_str
from time import clock

x0 = 0
y0 = 255
x2 = 255
y2 = 0
refPt = []
cropping = False


lk_params = dict( winSize  = (15, 15),
                  maxLevel = 2,
                  criteria = (cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 0.03))

feature_params = dict( maxCorners = 500,
                       qualityLevel = 0.3,
                       minDistance = 7,
                       blockSize = 7 )


class App:
    def __init__(self, video_src):
        self.v = 0
        self.fps = 0
        self.track_len = 10
        self.detect_interval = 5
        self.tracks = []
        self.frame_idx = 0
        
    def run(self):
        self.start = time.time() #Запуск таймера
        ff = 0
        on = 1
        while True:
            frame = cv2.imread('People7.jpg') #Загрузка изображения

            frame_gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY) #Делаем его черно-белым
            vis = frame.copy()

            def click_and_crop(event, x, y, flags, param):
                # grab references to the global variables
                global x0, y0, x2, y2, cropping
            #Поиск контрастных точек    
            if len(self.tracks) > 0:
                img0, img1 = self.prev_gray, frame_gray
                p0 = np.float32([tr[-1] for tr in self.tracks]).reshape(-1, 1, 2)
                p1, st, err = cv2.calcOpticalFlowPyrLK(img0, img1, p0, None, **lk_params)
                p0r, st, err = cv2.calcOpticalFlowPyrLK(img1, img0, p1, None, **lk_params)
                d = abs(p0-p0r).reshape(-1, 2).max(-1)
                good = d < 1
                new_tracks = []
                #Создание массива из точек
                for tr, (x, y), good_flag in zip(self.tracks, p1.reshape(-1, 2), good):
                    if not good_flag:
                        continue
                    tr.append((x, y))
                    if len(tr) > self.track_len:
                        del tr[0]
                    new_tracks.append(tr)
                    cv2.circle(vis, (x, y), 2, (0, 255, 0), -1) #Отрисовка точек
                if self.tracks == new_tracks:
                    ff = 1
                self.tracks = new_tracks
                #cv2.polylines(vis, [np.int32(tr) for tr in self.tracks], False, (0,255,0)) Отрисовка линий (требуется при работе с видеорядом
                draw_str(vis, (40, 40), 'track count: %d' % len(self.tracks)) #Вывод количества точек
                draw_str(vis, (40, 80), 'Press "Esc" for out')
            #Отработка частного случая
            if self.frame_idx % self.detect_interval == 0:
                mask = np.zeros_like(frame_gray)
                mask[:] = 255
                for x, y in [np.int32(tr[-1]) for tr in self.tracks]:
                    cv2.circle(mask, (x, y), 5, 0, -1)
                p = cv2.goodFeaturesToTrack(frame_gray, mask = mask, **feature_params)
                if p is not None:
                    for x, y in np.float32(p).reshape(-1, 2):
                        self.tracks.append([(x, y)])
            
            self.end = time.time()#Окончание таймера

            if ff == on:
                tt = float(self.end - self.start)
                print(tt)
                on = 2

            self.frame_idx += 1
            self.prev_gray = frame_gray
            #Изменение размера изображения
            fw = 600
            rr = float(fw) / vis.shape[1]
            dim = (fw, int(vis.shape[0]*rr))
            resized = cv2.resize(vis, dim, interpolation = cv2.INTER_AREA)

            cv2.imshow('lk_track', resized) #Вывод изображения

            ch = cv2.waitKey(1) # Закрытие окна при нажатии "Esc"
            if ch == 27:
                break

def main():
    import sys
    try:
        video_src = sys.argv[1]
    except:
        video_src = 0

    App(video_src).run()
    cv2.destroyAllWindows()

if __name__ == '__main__':
    main()
