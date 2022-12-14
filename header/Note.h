#ifndef NOTE_H
#define NOTE_H

#include <time.h>
#include "mType.h"

namespace note
{

    class User_note;
    class Common_note;
    class Long_note;

    //class
    class Note_List
    {
    private:
        Common_note *m_common_note; //스마트 포인터로 나중에 관리
        Long_note *m_long_note;

    public:
        Note_List();

    }

    class Common_note
    {
    private:
        
        //노트 시간 부
        mType::n_time_t time_typte;
        int rel_note_time;
        time_t note_time;        //노트 판정 시간

        char note_type;          //노트종류
        bool note_judg;          //판정
        mType::sound note_music; //노트 재생음

    public:
        Common_note();
        ~Common_note();

        //입력만 받는다
        //노트 종류, 시간 판정 포함
        mType::judgment_type note_judgment(char ch_note);

        //가까운 시간 판정
        static time_check(time_t t1, time_t t2);

        // getter 불 필요 할 듯

    }

    //긴 노트 구현 
    class Long_note
    {
    private:

        //시간 구현부
        mType::n_time_t time_typte;
        int rel_note_time;
        time_t note_start_time; //노트 시간 구현부분 
        time_t note_end_time;

        //반복 입력 체크
        int PERFECT_INPUT;
        int GOOD_INPUT;
        int NICE_INPUT;
        int BAD_INPUT;

        mType::judgment_type note_judg; //최종 노트 판정
        mType::sound note_music;        // 노트 재생 음

    public:
        //최종 노트 판정
        mType::judgment_type note_judgment(char ch_note);

        //가까운 시간 판정
        static time_check(time_t t1, time_t t2);

    }

    class User_note
    {
    private:
        time_t note_time;
        char note_type;

        ; //현재 시간 반환

    public:
        User_note(char note_type);

        static time_t time_check()
    }

}

#endif