#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

void generateMelody() {
    // Create JSON request
    nlohmann::json requestData = {
        {"key", "C"},
        {"tempo", 120},
        {"notes", 4}
    };

    // Send the request
    auto response = cpr::Post(
        cpr::Url{"http://ai-music-endpoint/api/generate"},
        cpr::Body{requestData.dump()},
        cpr::Header{{"Content-Type", "application/json"}}
    );

    // Parse the response
    if (response.status_code == 200) {
        auto melody = nlohmann::json::parse(response.text);
        for (const auto& note : melody["notes"]) {
            std::cout << "Note: " << note << std::endl;
        }
    } else {
        std::cerr << "Error: " << response.status_code << std::endl;
    }
}
