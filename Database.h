#include <vector>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include "cppconn/prepared_statement.h"

namespace DB {
	class Database {
	protected:
		sql::Driver            *driver;
		sql::Connection        *con;
		sql::Statement         *stmt;
		sql::ResultSet         *res;
		sql::PreparedStatement *prep_stmt;

	private:
		void DB::Database::Execute_Query(std::string,
			std::vector<std::string>);

	public:
		Database();

		Database(std::string, std::string,
			std::string, std::string, std::string);

		void Execute(std::string);

		std::vector<std::vector<std::string>>
			Execute(std::string, int);

		void Close();

		void Connect(std::string, std::string,
				std::string, std::string);

		void SetDatabase(std::string);

		void Insert(std::string, std::vector<std::string>);

		void InsertS(std::string, std::vector<std::string>);

		std::vector<std::vector<std::string>>
			Get(std::string, std::vector<std::string>, int);

		std::vector<std::vector<std::string>>
			Get(std::string, int);

		void Update(std::string, std::vector<std::string>);

		void Delete(std::string, std::vector<std::string>);

	};
};
