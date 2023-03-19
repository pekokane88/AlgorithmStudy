-- 집계 함수 AVG 와 반올림 함수 round 를 이용. round(num)  은 round(num, 0) 과 같은 의미이다.
SELECT ROUND(AVG(DAILY_FEE)) AS AVERAGE_FEE FROM CAR_RENTAL_COMPANY_CAR
WHERE CAR_TYPE = 'SUV';
