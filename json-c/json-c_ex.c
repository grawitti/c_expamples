#include <stdio.h>
#include <json-c/json.h>

int main()
{
	// Create JSON objects
	json_object *family = json_object_new_string("ip");
	json_object *name = json_object_new_string("mytable");

    json_object *table = json_object_new_object();
    json_object_object_add(table, "family", family);
    json_object_object_add(table, "name", name);

    json_object *add = json_object_new_object();
    json_object_object_add(add, "table", table);

    json_object *nadd = json_object_new_object();
    json_object_object_add(nadd, "add", add);

	json_object *nftables = json_object_new_array();
    json_object_array_add(nftables, nadd);

    json_object *root = json_object_new_object();
    json_object_object_add(root, "nftables", nftables);

    printf("%s\n", json_object_to_json_string(root));
    printf("%s\n", json_object_to_json_string_ext(root,JSON_C_TO_STRING_PRETTY));

    return 0;
}
