<x-app-layout>
    <x-slot name="header">
        <h2 class="font-semibold text-xl text-gray-800 dark:text-gray-200 leading-tight">
            {{ __('CRUD Operation') }}
        </h2>
    </x-slot>

    <div class="py-12">
        <div class="max-w-7xl mx-auto sm:px-6 lg:px-8">
            <div class="bg-white dark:bg-gray-800 overflow-hidden shadow-sm sm:rounded-lg">
                <div class="p-6 text-gray-900 dark:text-gray-100">
                
                <table class="border-collapse table-auto w-full text-sm">
                    <thead>
                        <tr>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">ID</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">Name</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">Email</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">Registration Date</th>
                        </tr>
                    </thead>
                    <tbody class="bg-dark">
                        @foreach($User as $userdata)
                        <tr>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">{{$userdata->id}}</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">{{$userdata->name}}</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">{{$userdata->email}}</th>
                        <th class="border-b font-meium p-4 pl-8 pt-0 pb-3 text-slate-300 text-left">{{$userdata->created_at}}</th>
                        
                        <td>
                            <a href="#" class="border border-blue-500 px-4 py-2 rounded-md">Details</a>
                            <a href="#" class="border border-blue-500 px-4 py-2 rounded-md">Update</a>
                            <form method = "POST" action="{{route('crud.destroy', $userdata->id)}}" class="inline">
                                @csrf
                                @method("delete")
                                <button class="border border-blue-500 px-4 py-2 rounded-md">Delete</a>
                        </td>

                        </tr>
                        @endforeach
 
                    </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
</x-app-layout>
