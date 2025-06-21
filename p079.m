path = '0079_keylog.txt';
fileID = fopen(path, 'r');
data = {};
line = fgetl(fileID);
while ischar(line)
    data{end + 1} = strtrim(line);
    line = fgetl(fileID);
end
fclose(fileID);

[M, used_indices] = passcode_derivation(data);    % 1-based indices (1 = digit 0)
G = digraph(M(used_indices, used_indices));       % build graph from relevant digits only

sorted_order = toposort(G);                       % topological sort
actual_digits = used_indices(sorted_order) - 1;   % convert to actual digits

passcode = join(string(actual_digits), '');
disp("Recovered Passcode: " + passcode);

% Visualize
figure;
plot(G, 'NodeLabel', string(actual_digits));

function [M, used_indices] = passcode_derivation(logings)
    M = zeros(10, 10);       % adjacency matrix
    used = false(1, 10);     % track used digits

    for i = 1:length(logings)
        login = logings{i};
        for j = 1:3
            idx = str2double(login(j)) + 1;
            used(idx) = true;
        end
        for j = 2:3
            from = str2double(login(j - 1)) + 1;
            to = str2double(login(j)) + 1;
            M(from, to) = 1;
        end
    end

    used_indices = find(used);  % keep 1-based for indexing
end
