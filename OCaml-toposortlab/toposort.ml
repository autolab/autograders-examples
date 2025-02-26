open Core

type graph = {
  nodes : int list;
  edges : (int * int) list;
}

let topological_sort (g : graph) : int list = 
  let visited = Hash_set.create (module Int) in
  (* Construct the adjacency list representation of the graph*)
  let adj_list = Int.Map.of_alist_multi g.edges in
  let rec dfs_helper (acc : int list) (node : int) = 
    if Hash_set.mem visited node then
      acc
    else
      let () = Hash_set.add visited node in
      let neighbors = (match Int.Map.find adj_list node with
      | Some neighbors -> neighbors
      | None -> []) in
      let acc = List.fold ~init:acc ~f:(dfs_helper) neighbors in
      node :: acc
  in
  List.fold ~init:[] ~f:(dfs_helper) g.nodes
