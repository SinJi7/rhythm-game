바닥부터 만드는 리듬게임
================
개발 툴
----------------
- visual Studio
- visual C++
- C++

소개
-----------------
리듬게임 알고리즘, gui 직접 구현하기!
그래픽 라이브러리는 사용하지 않고, 콘솔 환경. 
> https://printed.tistory.com/22 그래픽은 대충 이런 형식

음성처리 및 노트 파일 생성은 python 이용예정
```
import music21
```

- 알고리즘 / 그래픽 분리


알고리즘 구조 정리
=================
절차적 구조
-----------------
1. 파일을 불러와, 노트 생성
2. 노트 시각화 -> 알고리즘과는 별개로
3. 사용자 입력을 받는다.
    - 노트 판정 과정
        1. 오차범위 5초 이내 노트 탐색
        2. 이미 판정완료된 노트 제외
        3. 같은 버튼 탐색
        4. 시간 오차가 가장 적은 노트 판정
        5. p, g, n, b, m(위에서 판정 실패시) 판정
    - 반복되는 노트 판정 과정
        1. 일반노트 판정 4번까지 동일
        2. 반복노트 입력횟수 증가
            - p, g, n, b 입력 분리
        3. b 판정시간 이후 결과 출력 (이후는 miss 판정 알고리즘)
            - 입력을 종합하여 p, ex, g, b 판정
4. 노트판정 합산에 의한 점수 출력

객체 구조
------------------
### judgment_type - enum class
- 판정 종류
- PERFECT, GOOD, NICE, BAD, MISS, NO 

### common_note - class
- 일반 노트
- 멤버 변수
    - note_time : 노트 판정 시간
    - note_type : 노트의종류 (입력 타입)
    - note_judg : 판정
    - note_music : 노트 재생 음
- 멤버함수
    - pr judgment_type noete_judgment : 노트 종류 판정
    - input_time : 시간 입력 -> 판정시작 
    - static time_check : 얼마나 가까운 시간인지 출력
    - get_time

### long_note - class
- 긴 노트
- 멤버 변수
    - note_start_time : 노트 판정 시작 시간
    - note_end_tiem : 노트 판정 종료 시간
    - int PERFECT_INPUT : 반복 입력 체크
    - int GOOD_INPUT : "
    - int NICE_INPUT : "
    - int BAD_INPUT : "
    - judgment_type note_judg : 노트 판정
    - note_music : 노트 재생 음
- 멤버 함수
    - pr judgment_type noete_judgment : 노트 종류 판정
    - input_time() : 시간 입력 -> 판정 시작
    - static time_chek : 얼마나 가까운 시간인지 출력 -> 판정 시작 확인 용도

### music - class
- 노트 집합
