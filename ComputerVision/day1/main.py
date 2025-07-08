import cv2 as cv

vid = cv.VideoCapture(0)

while True:
    ret, frame = vid.read()

    cv2.imshow('test', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

vid.release()


cv2.destroyAllWindows()