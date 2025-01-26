/*class DepthFirstSearch: Managed
{
    protected ref array<BaseBuilding> m_ShortestPath = {};
    protected ref set<BaseBuilding> m_VisitedNodes = new set<BaseBuilding>();

    static array<BaseBuilding> Execute(notnull BaseBuilding start_node)
    {
        array<BaseBuilding> path = {};
        return DepthFirstSearch().Visit(start_node, path).GetShortestPath();
    }

    protected DepthFirstSearch Visit(BaseBuilding node, inout array<BaseBuilding> current_path)
    {
        // If this node is null or already visited, return.
        if (!node || m_VisitedNodes.Find(node) != -1) {
            return this;
		}
		
        // Add this node to the path and the visited nodes.
		current_path.Insert(node);
				
        m_VisitedNodes.Insert(node);

        // If this node is the goal, update the shortest path.
        if (node.IsNode() && (current_path.Count() < m_ShortestPath.Count() || m_ShortestPath.Count() == 0)) {
			m_ShortestPath.Clear();
			m_ShortestPath.Copy(current_path);
        }

        // Recursively call DFS on the child and sibling of the current node.
		array<SnapPoint> lowest_snap_points = node.GetLowestSnapPoints();
		foreach (auto lowest_snap_point: lowest_snap_points) {
			array<SnapPoint> attachments = lowest_snap_point.GetAttachments();			
			foreach (auto attachment: attachments) {				
				Visit(attachment.GetSource(), current_path);
			}
		}

        // Remove this node from the current path before backtracking.
        current_path.RemoveOrdered(current_path.Count() - 1);
		return this;
    }
	
	array<BaseBuilding> GetShortestPath()
	{
		return m_ShortestPath;
	}
}

enum SearchTreeType 
{
	PARENT,
	CHILDREN,
	BOTH
};

class BFS
{
	static BaseBuilding Execute(BaseBuilding root)
	{
		Queue<BaseBuilding> queue = new Queue<BaseBuilding>();
		set<BaseBuilding> hash = new set<BaseBuilding>();
		
		queue.Enqueue(root);
		hash.Insert(root);
		while (queue.Count() > 0) {
			BaseBuilding current = queue.Dequeue();
			if (current.IsNode()) {
				return current;
			}
			
			array<SnapPoint> lowest_snap_points = current.GetLowestSnapPoints();
			foreach (auto lowest_snap_point: lowest_snap_points) {
				array<SnapPoint> attachments = lowest_snap_point.GetAttachments();
				foreach (auto attachment: attachments) {
					BaseBuilding node = attachment.GetSource();					
					if (hash.Find(node) == -1) {
						queue.Enqueue(node);
						hash.Insert(node);
					}
				}
			}
		}
		
		return null;
	}
	
	static array<BaseBuilding> ShortestPath(BaseBuilding source, BaseBuilding target)
	{		
		auto queue = new Queue<BaseBuilding>();
		auto hash = new set<BaseBuilding>();
		
		queue.Enqueue(source);
		hash.Insert(source);
		
		while (queue.Count() > 0) {
			auto current = queue.Dequeue();
			if (current == target) {
				array<BaseBuilding> path = {};
				auto node = target;
				while (node) {
					path.Insert(node);
					node = node;
				}
				
				reversearray(path);				
				return path;
			}
			
			array<SnapPoint> lowest_snap_points = current.GetLowestSnapPoints();
			foreach (auto lowest_snap_point: lowest_snap_points) {
				array<SnapPoint> attachments = lowest_snap_point.GetAttachments();
				foreach (auto attachment: attachments) {
					BaseBuilding node1 = attachment.GetSource();					
					if (hash.Find(node1) == -1) {
						queue.Enqueue(node1);
						hash.Insert(node1);
					}
				}
			}
		}
		
		return {};
	}
}

class Queue<Class T>
{
	static const T EMPTY;
	
	protected ref array<T> m_Items = {};
		
	T Get(int n)
	{
		return m_Items[n];
	}
	
	void Set(T value, int n)
	{
		m_Items[n] = value;
	}
	
	void Enqueue(T value)
	{
		m_Items.InsertAt(value, m_Items.Count());
	}
	
	T Dequeue()
	{
		if (m_Items.Count() == 0) {
			return EMPTY;
		}
		
		T value = m_Items[0];
		m_Items.Remove(0);
		return value;
	}
	
	T Peek()
	{
		if (m_Items.Count() == 0) {
			return EMPTY;
		}
		
		return m_Items[0];
	}
	
	int Count()
	{
		return m_Items.Count();
	}
	
}