코드 풀이 및 깃허브 사용 절차

[준비 사항]
1. Git 설치 (https://git-scm.com/downloads/win으로 이동하여 64-bit Git for Windows Setup 설치)
2. Git Bash 실행 후, 사용할 로컬 폴더로 이동
3. git init 커맨드를 통해 Git 초기화
4. 아래 명령어를 통해 이름 및 이메일 지정 
  git config --global user.email "E-mail address"
  git config --global user.name "Name"
5. 아래 명령어를 통해 리포지토리 클론
   git clone https://github.com/Wanted-1st-generation/daily-algorithms.git
6. git checkout "branch name"을 통해 자신의 브랜치로 체크아웃 (브랜치명은 이메일 로컬 파트입니다.)

----------------------------------------------------------------------------------------------
[일일 문제 풀이 절차]

1. 클론한 로컬 폴더로 이동하여 자신의 풀이 파일을 연다.(파일명: "문제번호_사용자명.cpp")
2. 주어진 문제를 풀이하여 해당 파일을 수정한다.
3. 수정을 마쳤으면 다음 명령어를 통해 수정된 파일을 스테이징 영역에 추가한다.
   (현재 브랜치를 확인 후 main이나 다른 브랜치일 경우 준비 사항의 6번 커맨드를 통해 체크아웃)
   git add .
4. 다음 명령어를 통해 커밋한다.
   git commit -m "feat: Solve_문제번호_사용자명"
5. 다음 명령어를 통해 푸시한다.
   git push

----------------------------------------------------------------------------------------------
[주말 코드 리뷰 절차]
- Pull Request 생성
1. https://github.com/Wanted-1st-generation/daily-algorithms에 접속한다.
2. 상단의 버튼을 통해 Pull Request 탭으로 이동한다.
3. 우측에 있는 New Pull Request 버튼을 통해 Pull Request 생성 창으로 이동한다.
4. compare 브랜치(오른쪽)를 자신의 브랜치로 변경한다.
5. 코드 변경 사항을 확인하고, Create Pull Request 버튼을 통래 PR을 생성한다.
   
- 코드 리뷰
1. https://github.com/Wanted-1st-generation/daily-algorithms에 접속한다.
2. 상단의 버튼을 통해 Pull Request 탭으로 이동한다.
3. 다른 사람이 생성한 Pull Request를 확인한다.
4. 상위의 Files changed 버튼을 통해 작성된 코드를 검토한다.
5. 검토를 마친 뒤 Review changes 버튼을 클릭해 리뷰 총평 코멘트를 남긴다.
6. Submit review 버튼을 클릭해 리뷰를 작성한다.
