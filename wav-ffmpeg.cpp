#include <iostream> 
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main(int argc, char* argv[]) { 
   // TODO
   // EMBED FFMPEG NOW !!!
   // ADD ICON !!
   string work_folder = "ffmpeg converted";
   if (!fs::is_directory(work_folder) || !fs::exists(work_folder)) {
         fs::create_directory(work_folder);
   }

   for(int i = 1; i < argc; i++) {

      string file = argv[i];
      fs::path p(argv[i]);

      string new_file {p.filename().string()};

      size_t lastindex = new_file.find_last_of("."); 
      string rawname = new_file.substr(0, lastindex);
      new_file = rawname + ".wav";

      string cwd = fs::current_path().string() + "\\" + work_folder + "\\";
      string cmd("ffmpeg -i \"" + file + "\" \"" + cwd + new_file + "\"");
      system(cmd.c_str());
   }
   return 0; 
}