#include <iostream>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/json.hpp>

using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;

int main() {
    // Inicializar la instancia MongoDB (debe ejecutarse una vez por aplicación)
    mongocxx::instance instance{};
    // Conectarse a la base de datos
    mongocxx::client client{mongocxx::uri{}};

    // Seleccionar la base de datos y la colección
    auto db = client["mydatabase"];
    auto collection = db["users"];

    // Insertar un documento
    document doc1{};
    doc1 << "name" << "Alice" << "age" << 30 << "email" << "alice@example.com";
    collection.insert_one(doc1.view());

    // Consultar todos los documentos
    auto cursor = collection.find({});
    std::cout << "Documentos en la colección:" << std::endl;
    for (auto& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }

    // Actualizar un documento
    collection.update_one(document{} << "name" << "Alice" << finalize,
                          document{} << "$set" << document{} << "age" << 31 << finalize);

    // Consultar un solo documento
    auto maybe_result = collection.find_one(document{} << "name" << "Alice" << finalize);
    if (maybe_result) {
        std::cout << "Documento actualizado:" << std::endl;
        std::cout << bsoncxx::to_json(*maybe_result) << std::endl;
    }

    // Eliminar un documento
    collection.delete_one(document{} << "name" << "Alice" << finalize);
    std::cout << "Documento eliminado." << std::endl;

    return 0;
}
