-- case/when 구문을 이용하여 해결. case 의 종료에는 반드시 end 가 와야 한다.
SELECT PT_NAME, PT_NO, GEND_CD, AGE, 
    CASE 
        WHEN TLNO IS NULL THEN 'NONE' 
        ELSE TLNO
    END AS TLNO
    FROM PATIENT
WHERE AGE <= 12 AND GEND_CD = 'W'
ORDER BY AGE DESC, PT_NAME;
