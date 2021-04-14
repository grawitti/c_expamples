#include <stdio.h>
#include <jansson.h>
#include <nftables/libnftables.h>

int main(int argc, char const *argv[])
{
    json_t *jt = json_pack("{s:[{s{s{s:s, s:s}}}]}",
                           "nftables", "add", "table",
                           "family", "ip", "name", "mytable");

    json_dumpf(jt, stdout, JSON_INDENT(4));

    struct nft_ctx *nft;

    nft = nft_ctx_new(NFT_CTX_DEFAULT);
    if (!nft)
        return 1;

    char *list_cmd = json_dumps(jt,JSON_INDENT(4));
    printf("%s\n", list_cmd);

    nft_ctx_output_set_json(nft, 1);

    if (nft_ctx_buffer_output(nft) || nft_run_cmd_from_buffer(nft, list_cmd, sizeof(list_cmd)))
        return 1;

    return 0;
}
