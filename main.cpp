#include <Novice.h>
using namespace std;
#include"sqlite/sqlite3.h";

const char kWindowTitle[] = "LE2B_27_ワタナベ_ライキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	//データベース関連//

	int number[100] = { };
	int i = 0;

	//エラーメッセージ
	char* error;


	//データベースの作成
	sqlite3* db;
	sqlite3_stmt* stmt;
	sqlite3_open("test1.db", &db);

	//テーブルの作成
	int createResultCode = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS tb1(id integer primary key autoincrement, number INT,name varchar(100));",		//ここで決める
		0, 0, &error);
	if (createResultCode != SQLITE_OK) {
		Novice::ScreenPrintf(0, 0, "error");
	}

	///////////////
	 //INSERT文↓//
	///////////////

	//INSERT文の準備
	int InsertCode = sqlite3_prepare_v2(db, "INSERT INTO tb1(number,name) VALUES(1,'A');",//ここで何を追加するか決める
									-1, &stmt, 0);

	if (InsertCode != SQLITE_OK) {
		Novice::ScreenPrintf(0, 20, "error");
		sqlite3_close(db);
	}

	//INSERT文の実行
	int InsertResultCode = sqlite3_step(stmt);
	if (InsertResultCode != SQLITE_DONE) {
		Novice::ScreenPrintf(0, 40, "error");
	}

	int Insert = sqlite3_finalize(stmt);
	if (Insert != SQLITE_OK) {
		Novice::ScreenPrintf(0, 60, "error");
	}

	///////////////
	 //INSERT文↑//
	///////////////


	///////////////
	 //SELRCT文↓//
	///////////////

	////SELECT文の準備
	//int SelectCode = sqlite3_prepare_v2(db, "SELECT number FROM tb1",	//ここでどこを読み込むのか決める
	//	-1, &stmt, 0);
	//if (SelectCode != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 20, "error");
	//	sqlite3_close(db);
	//}
	////行を読み取る
	//int SelectResultCode = sqlite3_step(stmt);
	//while (SelectResultCode == SQLITE_ROW) {

	//	number[i] = sqlite3_column_int(stmt, 0);

	//	SelectResultCode = sqlite3_step(stmt);

	//	i++;
	//}


	//int SELECT = sqlite3_finalize(stmt);
	//if (SELECT != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 40, "error");
	//}

	///////////////
	 //SELRCT文↑//
	///////////////



	///////////////
	 //UPDATE文↓//
	///////////////


	////UPDATE文の準備
	//int UpdateCode = sqlite3_prepare_v2(db, "UPDATE tb1 SET name='Z' where number=1",	//ここでどこを更新するか決める
	//	-1, &stmt, 0);
	//if (UpdateCode != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 20, "error");
	//	sqlite3_close(db);
	//}

	////UPDATE文の実行
	//int UpdateResultCode = sqlite3_step(stmt);
	//if (UpdateResultCode != SQLITE_DONE) {
	//	Novice::ScreenPrintf(0, 40, "error");
	//}

	//int Update = sqlite3_finalize(stmt);
	//if (Update != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 60, "error");
	//}


	///////////////
	 //UPDATE文↑//
	///////////////



	///////////////
	 //DELETE文↓//
	///////////////

	////DELETE文の準備
	//int DeleteCode = sqlite3_prepare_v2(db, "DELETE FROM tb1 where number=1",	//ここでどこを消すか決める
	//	-1, &stmt, 0);
	//if (DeleteCode != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 20, "error");
	//	sqlite3_close(db);
	//}

	////DELETE文の実行
	//int DeleteResultCode = sqlite3_step(stmt);
	//if (DeleteResultCode != SQLITE_DONE) {
	//	Novice::ScreenPrintf(0, 40, "error");
	//}

	//int Delete = sqlite3_finalize(stmt);
	//if (Delete != SQLITE_OK) {
	//	Novice::ScreenPrintf(0, 60, "error");
	//}


	///////////////
	 //DELETE文↑//
	///////////////


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///





		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::ScreenPrintf(0, 100, "%d",number[2]);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
