-- 두 테이블에서 다중 select 를 하는 문제. Join 으로 묶은 뒤 조건 문을 설정해준다.
SELECT F.FLAVOR FROM FIRST_HALF AS F
JOIN ICECREAM_INFO AS I ON I.FLAVOR = F.FLAVOR
where F.TOTAL_ORDER > 3000 AND I.INGREDIENT_TYPE = 'fruit_based'
ORDER BY F.TOTAL_ORDER DESC;
